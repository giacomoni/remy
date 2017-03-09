/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   link_def.hh
 * Author: lg317
 *
 * Created on 08 March 2017, 16:26
 */

#ifndef LINK_DEF_HH
#define LINK_DEF_HH

#include <utility>

#include "link.hh"

using namespace std;

template <class NextHop>
void Link::tick( NextHop & next, const double & tickno )
{
  _pending_packet.tick( next, tickno );

  if ( _pending_packet.empty() ) {
    if ( not _buffer.empty() ) {
      _pending_packet.accept( _buffer.front(), tickno );
      _buffer.pop_front();
    }
  }
}


#endif /* LINK_DEF_HH */

