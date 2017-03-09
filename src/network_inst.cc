/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "networkdef.hh"
#include "sendergang.hh"
#include "rat.hh"
#include "fish.hh"


template class Network<SenderGang<Rat, TimeSwitchedSender<Rat>>, SenderGang<Rat, TimeSwitchedSender<Rat>>>;
template class Network<SenderGang<Fish, TimeSwitchedSender<Fish> >, SenderGang<Fish, TimeSwitchedSender<Fish> > >;

template class Network<SenderGang<Rat, ExternalSwitchedSender<Rat> >, SenderGang<Rat, ExternalSwitchedSender<Rat> > >;
template class Network<SenderGang<Fish, ExternalSwitchedSender<Fish> >, SenderGang<Fish, ExternalSwitchedSender<Fish> > >;