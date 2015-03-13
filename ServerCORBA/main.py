#!/usr/bin/env python

import CORBA
import PortableServer
import CorbaSevrer
import CorbaSevrer__POA

import sys

class Manager_i(CorbaSevrer__POA.Manager):
	def testManager(self,msg):
		print "Server got "+msg
		return "Echo:"+msg

orb = CORBA.ORB_init(sys.argv, CORBA.ORB_ID) 
poa = orb.resolve_initial_references("RootPOA")

manager_i = Manager_i() # create manager instanse
manager_o = manager_i._this() # create manager object

poaManager = poa._get_the_POAManager()
poaManager.activate()

msg = "Is you alive?"
result = manager_o.testManager(msg)

print "Result:"+result