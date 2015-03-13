#!/usr/bin/env python

from omniORB import CORBA
import sys
import CorbaServer

orb = CORBA.ORB_init(sys.argv, CORBA.ORB_ID)
ior = sys.argv[1] # get IOR of server
obj = orb.string_to_object(ior)
eo = obj._narrow(CorbaServer.Manager)

if eo is None:
	print "Eo object is None"
	sys.exit(1)

msg = "Are u alive"
result = eo.testManager(msg)

print "Client goted:"+result