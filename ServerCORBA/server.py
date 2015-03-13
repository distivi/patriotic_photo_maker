#!/usr/bin/env python

import CORBA
import PortableServer
import CorbaServer
import CorbaServer__POA

import sys

class Test:
	def __init__(self,info):
		print "TEst"+info

class Manager_i(CorbaServer__POA.Manager):
	def testManager(self,msg):
		test = Test(msg)
		print "Server got "+msg
		return "Echo:"+msg

orb = CORBA.ORB_init(sys.argv, CORBA.ORB_ID) 
poa = orb.resolve_initial_references("RootPOA")

manager_i = Manager_i() # create manager instanse
manager_o = manager_i._this() # create manager object

print "ORB Object:"+orb.object_to_string(manager_o) # print IOR adress required by client to connect to the server

poaManager = poa._get_the_POAManager()
poaManager.activate()

orb.run()