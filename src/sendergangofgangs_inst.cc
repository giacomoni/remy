/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sendergangofgangsdef.h"
#include "rat.hh"
#include "link.hh"
#include "receiver.hh"
#include "fish.hh"


template class SenderGangofGangs<SenderGang<Rat, TimeSwitchedSender<Rat>>, SenderGang<Rat, TimeSwitchedSender<Rat>>>;
template class SenderGangofGangs<SenderGang<Fish, TimeSwitchedSender<Fish>>, SenderGang<Fish, TimeSwitchedSender<Fish>>>;

template class SenderGangofGangs<SenderGang<Rat, ExternalSwitchedSender<Rat>>, SenderGang<Rat, ExternalSwitchedSender<Rat>>>;
template class SenderGangofGangs<SenderGang<Fish, ExternalSwitchedSender<Fish>>, SenderGang<Fish, ExternalSwitchedSender<Fish>>>;

template class SenderGangofGangs<SenderGang<Rat, ByteSwitchedSender<Rat>>, SenderGang<Rat, ByteSwitchedSender<Rat>>>;
template class SenderGangofGangs<SenderGang<Fish, ByteSwitchedSender<Fish>>, SenderGang<Fish, ByteSwitchedSender<Fish>>>;



template void SenderGangofGangs<SenderGang<Rat, TimeSwitchedSender<Rat>>, SenderGang<Rat, TimeSwitchedSender<Rat>>>::tick<Link>( Link & next, Receiver & rec, const double & tickno );
template void SenderGangofGangs<SenderGang<Rat, ExternalSwitchedSender<Rat> >, SenderGang<Rat, ExternalSwitchedSender<Rat> > >::tick<Link>(Link&, Receiver&, double const&);

template void SenderGangofGangs<SenderGang<Rat, TimeSwitchedSender<Rat>>, SenderGang<Rat, TimeSwitchedSender<Rat>>>::run_senders<Link>( Link & next, Receiver & rec, const unsigned int num_sending, const double & tickno );


template void SenderGangofGangs<SenderGang<Fish, TimeSwitchedSender<Fish> >, SenderGang<Fish, TimeSwitchedSender<Fish> > >::tick<Link>(Link&, Receiver&, double const&);
template void SenderGangofGangs<SenderGang<Fish, ExternalSwitchedSender<Fish> >, SenderGang<Fish, ExternalSwitchedSender<Fish> > >::tick<Link>(Link&, Receiver&, double const&);

