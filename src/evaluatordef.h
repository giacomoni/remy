/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   evaluatordef.h
 * Author: lg317
 *
 * Created on 08 March 2017, 14:05
 */

#ifndef EVALUATORDEF_H
#define EVALUATORDEF_H

#include "evaluator.hh"

template <typename T>
Evaluator< T >::Evaluator( const ConfigRange & range )
  : _prng_seed( global_PRNG()() ), /* freeze the PRNG seed for the life of this Evaluator */
    _tick_count( range.simulation_ticks ),
    _configs()
{
  // add configs from every point in the cube of configs
  for (double link_ppt = range.link_ppt.low; link_ppt <= range.link_ppt.high; link_ppt += range.link_ppt.incr) {
    for (double rtt = range.rtt.high; rtt <= range.rtt.high; rtt += range.rtt.incr) {
      for (unsigned int senders = range.num_senders.low; senders <= range.num_senders.high; senders += range.num_senders.incr) {
        for (double on = range.mean_on_duration.low; on <= range.mean_on_duration.high; on += range.mean_on_duration.incr) {
          for (double off = range.mean_off_duration.low; off <= range.mean_off_duration.high; off += range.mean_off_duration.incr) {
            for ( double buffer_size = range.buffer_size.low; buffer_size <= range.buffer_size.high; buffer_size += range.buffer_size.incr) {
              for ( double loss_rate = range.stochastic_loss_rate.low; loss_rate <= range.stochastic_loss_rate.high; loss_rate += range.stochastic_loss_rate.incr) {
                _configs.push_back( NetConfig().set_link_ppt( link_ppt ).set_delay( rtt ).set_num_senders( senders ).set_on_duration( on ).set_off_duration(off).set_buffer_size( buffer_size ).set_stochastic_loss_rate( loss_rate ) );
                if ( range.stochastic_loss_rate.isOne() ) { break; }
              }
              if ( range.buffer_size.isOne() ) { break; }
            }
            if ( range.mean_off_duration.isOne() ) { break; }
          }
          if ( range.mean_on_duration.isOne() ) { break; }
        }
        if ( range.num_senders.isOne() ) { break; }
      }
      if ( range.rtt.isOne() ) { break; }
    }
    if ( range.link_ppt.isOne() ) { break; }
  }
}

template <typename T>
ProblemBuffers::Problem Evaluator< T >::_ProblemSettings_DNA( void ) const
{
  ProblemBuffers::Problem ret;

  ProblemBuffers::ProblemSettings settings;
  settings.set_prng_seed( _prng_seed );
  settings.set_tick_count( _tick_count );

  ret.mutable_settings()->CopyFrom( settings );

  for ( auto &x : _configs ) {
    RemyBuffers::NetConfig *config = ret.add_configs();
    *config = x.DNA();
  }

  return ret;
}

template <typename T>
Outcome<T> Evaluator< T >::score( T & run_actions,
				     const bool trace, const double carefulness ) const
{
  return Evaluator<T>::score( run_actions, _prng_seed, _configs, trace, _tick_count * carefulness );
}

#endif /* EVALUATORDEF_H */

