/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   outcomedef.hh
 * Author: lg317
 *
 * Created on 08 March 2017, 14:27
 */

#ifndef OUTCOMEDEF_HH
#define OUTCOMEDEF_HH

#include "outcome.hh"

using namespace std;

template <typename T>
Outcome<T>::Outcome( const AnswerBuffers::Outcome & dna )
  : score( dna.score() ), throughputs_delays(), used_actions() {
  for ( const auto &x : dna.throughputs_delays() ) {
    vector< pair< double, double > > tp_del;
    for ( const auto &result : x.results() ) {
      tp_del.emplace_back( result.throughput(), result.delay() );
    }

    throughputs_delays.emplace_back( NetConfig( x.config() ), tp_del );
  }
}

template <typename T>
AnswerBuffers::Outcome Outcome<T>::DNA( void ) const
{
  AnswerBuffers::Outcome ret;

  for ( const auto & run : throughputs_delays ) {
    AnswerBuffers::ThroughputsDelays *tp_del = ret.add_throughputs_delays();
    tp_del->mutable_config()->CopyFrom( run.first.DNA() );

    for ( const auto & x : run.second ) {
      AnswerBuffers::SenderResults *results = tp_del->add_results();
      results->set_throughput( x.first ); 
      results->set_delay( x.second );
    }
  }

  ret.set_score( score );

  return ret;
}

#endif /* OUTCOMEDEF_HH */

