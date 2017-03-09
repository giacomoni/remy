/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "fishdef.hh"
#include "link.hh"

template void Fish::send<Link>( const unsigned int id, Link & next, const double & tickno );