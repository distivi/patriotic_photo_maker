# Python stubs generated by omniidl from server.idl
# DO NOT EDIT THIS FILE!

import omniORB, _omnipy
from omniORB import CORBA, PortableServer
_0_CORBA = CORBA


_omnipy.checkVersion(4,2, __file__, 1)

try:
    property
except NameError:
    def property(*args):
        return None


#
# Start of module "CorbaServer"
#
__name__ = "CorbaServer"
_0_CorbaServer = omniORB.openModule("CorbaServer", r"server.idl")
_0_CorbaServer__POA = omniORB.openModule("CorbaServer__POA", r"server.idl")


# interface Manager
_0_CorbaServer._d_Manager = (omniORB.tcInternal.tv_objref, "IDL:CorbaServer/Manager:1.0", "Manager")
omniORB.typeMapping["IDL:CorbaServer/Manager:1.0"] = _0_CorbaServer._d_Manager
_0_CorbaServer.Manager = omniORB.newEmptyClass()
class Manager :
    _NP_RepositoryId = _0_CorbaServer._d_Manager[1]

    def __init__(self, *args, **kw):
        raise RuntimeError("Cannot construct objects of this type.")

    _nil = CORBA.Object._nil


_0_CorbaServer.Manager = Manager
_0_CorbaServer._tc_Manager = omniORB.tcInternal.createTypeCode(_0_CorbaServer._d_Manager)
omniORB.registerType(Manager._NP_RepositoryId, _0_CorbaServer._d_Manager, _0_CorbaServer._tc_Manager)

# Manager operations and attributes
Manager._d_testManager = (((omniORB.tcInternal.tv_string,0), ), ((omniORB.tcInternal.tv_string,0), ), None)

# Manager object reference
class _objref_Manager (CORBA.Object):
    _NP_RepositoryId = Manager._NP_RepositoryId

    def __init__(self, obj):
        CORBA.Object.__init__(self, obj)

    def testManager(self, *args):
        return self._obj.invoke("testManager", _0_CorbaServer.Manager._d_testManager, args)

omniORB.registerObjref(Manager._NP_RepositoryId, _objref_Manager)
_0_CorbaServer._objref_Manager = _objref_Manager
del Manager, _objref_Manager

# Manager skeleton
__name__ = "CorbaServer__POA"
class Manager (PortableServer.Servant):
    _NP_RepositoryId = _0_CorbaServer.Manager._NP_RepositoryId


    _omni_op_d = {"testManager": _0_CorbaServer.Manager._d_testManager}

Manager._omni_skeleton = Manager
_0_CorbaServer__POA.Manager = Manager
omniORB.registerSkeleton(Manager._NP_RepositoryId, Manager)
del Manager
__name__ = "CorbaServer"

#
# End of module "CorbaServer"
#
__name__ = "server_idl"

_exported_modules = ( "CorbaServer", )

# The end.
