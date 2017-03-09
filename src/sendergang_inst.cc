/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sendergangdef.hh"
#include "rat.hh"
#include "fin.hh"
#include "link.hh"
#include "fish.hh"

template class SwitchedSender<Rat>;
template class SwitchedSender<Fish>;

template class TimeSwitchedSender<Rat>;
template class TimeSwitchedSender<Fish>;

template class ByteSwitchedSender<Rat>;
template class ByteSwitchedSender<Fish>;

template class ExternalSwitchedSender<Rat>;
template class ExternalSwitchedSender<Fish>;

template class SenderGang<Rat, TimeSwitchedSender<Rat> >;
template class SenderGang<Fish, TimeSwitchedSender<Fish> >;

template class SenderGang<Rat, ExternalSwitchedSender<Rat> >;
template class SenderGang<Fish, ExternalSwitchedSender<Fish> >;

template class SenderGang<Rat, ByteSwitchedSender<Rat> >;
template class SenderGang<Fish, ByteSwitchedSender<Fish> >;

template void SenderGang<Rat, TimeSwitchedSender<Rat> >::run_senders<Link>(Link& next, Receiver& rec, const unsigned int num_sending, const double& tickno);
template void SenderGang<Fish, TimeSwitchedSender<Fish> >::run_senders<Link>(Link&, Receiver&, unsigned int, double const&);

template void SenderGang<Rat, ExternalSwitchedSender<Rat> >::run_senders<Link>(Link&, Receiver&, unsigned int, double const&);
template void SenderGang<Fish, ExternalSwitchedSender<Fish> >::run_senders<Link>(Link&, Receiver&, unsigned int, double const&);