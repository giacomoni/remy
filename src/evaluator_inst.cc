/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "evaluatordef.h"


//Instantiate some member functions of Evaluator
template <>
ProblemBuffers::Problem Evaluator< WhiskerTree >::DNA( const WhiskerTree & whiskers ) const
{
  ProblemBuffers::Problem ret = _ProblemSettings_DNA();
  ret.mutable_whiskers()->CopyFrom( whiskers.DNA() );

  return ret;
}

template <>
ProblemBuffers::Problem Evaluator< FinTree >::DNA( const FinTree & fins ) const
{
  ProblemBuffers::Problem ret = _ProblemSettings_DNA();
  ret.mutable_fins()->CopyFrom( fins.DNA() );

  return ret;
}

template <>
Outcome<WhiskerTree> Evaluator< WhiskerTree >::score( WhiskerTree & run_whiskers,
             const unsigned int prng_seed,
             const vector<NetConfig> & configs,
             const bool trace,
             const unsigned int ticks_to_run )
{
  PRNG run_prng( prng_seed );

  run_whiskers.reset_counts();

  /* run tests */
  Outcome<WhiskerTree> the_outcome;
  int i = 0;
  for ( auto &x : configs ) {
    /* run once */
      
    Network<SenderGang<Rat, TimeSwitchedSender<Rat>>,
      SenderGang<Rat, TimeSwitchedSender<Rat>>> network1( Rat( run_whiskers, trace ), run_prng, x );
    network1.run_simulation( ticks_to_run );
    
    
    the_outcome.score += network1.senders().utility();
    the_outcome.throughputs_delays.emplace_back( x, network1.senders().throughputs_delays() );
    i++;
  }

  the_outcome.used_actions = run_whiskers;

  return the_outcome;
}

template <>
Outcome<FinTree> Evaluator< FinTree >::score( FinTree & run_fins,
             const unsigned int prng_seed,
             const vector<NetConfig> & configs,
             const bool trace,
             const unsigned int ticks_to_run )
{
  PRNG run_prng( prng_seed );
  unsigned int fish_prng_seed( run_prng() );

  run_fins.reset_counts();

  /* run tests */
  Outcome<FinTree> the_outcome;
  for ( auto &x : configs ) {
    /* run once */
    Network<SenderGang<Fish, TimeSwitchedSender<Fish>>,
      SenderGang<Fish, TimeSwitchedSender<Fish>>> network1( Fish( run_fins, fish_prng_seed, trace ), run_prng, x );
    network1.run_simulation( ticks_to_run );
    
    the_outcome.score += network1.senders().utility();
    the_outcome.throughputs_delays.emplace_back( x, network1.senders().throughputs_delays() );
  }

  the_outcome.used_actions = run_fins;

  return the_outcome;
}

template <>
Outcome<WhiskerTree> Evaluator< WhiskerTree >::parse_problem_and_evaluate( const ProblemBuffers::Problem & problem )
{
  vector<NetConfig> configs;
  for ( const auto &x : problem.configs() ) {
    configs.emplace_back( x );
  }

  WhiskerTree run_whiskers = WhiskerTree( problem.whiskers() );

  return Evaluator< WhiskerTree >::score( run_whiskers, problem.settings().prng_seed(),
			   configs, false, problem.settings().tick_count() );
}

template <>
Outcome<FinTree> Evaluator< FinTree >::parse_problem_and_evaluate( const ProblemBuffers::Problem & problem )
{
  vector<NetConfig> configs;
  for ( const auto &x : problem.configs() ) {
    configs.emplace_back( x );
  }

  FinTree run_fins = FinTree( problem.fins() );

  return Evaluator< FinTree >::score( run_fins, problem.settings().prng_seed(),
         configs, false, problem.settings().tick_count() );
}

//instantiate class Evaluator for WhiskerTree and FinTree
template class Evaluator< WhiskerTree>;
template class Evaluator< FinTree >;
