/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fishdef.hh
 * Author: lg317
 *
 * Created on 08 March 2017, 17:22
 */

#ifndef FISHDEF_HH
#define FISHDEF_HH

#include <cassert>
#include <utility>

#include "fish.hh"

using namespace std;

template <class NextHop>
void Fish::send( const unsigned int id, NextHop & next, const double & tickno )
{
  if ( tickno < _next_send_time ) { return; }
  
  assert( _packets_sent >= _largest_ack + 1 );

  if ( _lambda == 0 ) {
    /* initial lambda  */
    const Fin & current_fin( _fins.use_fin( _memory, _track ) );
    _update_lambda( current_fin.lambda() );
  }

  for ( unsigned int i = 0; i < _batch_size; i++ ) {
    Packet p( id, _flow_id, tickno, _packets_sent );
    _packets_sent++;
    next.accept( p, tickno );
  }
  _update_send_time( tickno );
}


#endif /* FISHDEF_HH */

