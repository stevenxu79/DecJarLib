ifeq ($(shell uname), Linux)
  CC         = g++ -fPIC 
  LIBLINK    = -shared 
  INCLUDEDIR = -I /opt/jdk1.8.0_111/include -I /opt/jdk1.8.0_111/include/linux
  TARGET     = libdecrypt.so
endif

ifeq ($(shell uname), Darwin)
  CC		 = g++ 
  LIBLINK    = -dynamiclib
  TARGET     = libdecrypt.dylib
  INCLUDEDIR = -I/System/Library/Frameworks/JavaVM.framework/Headers
endif

OBJS = decrypt.o com_seassoon_encrypt_Decrypt.o com_seassoon_encrypt_Decrypt.o org_springframework_core_LocalVariableTableParameterNameDiscoverer.o org_springframework_core_type_classreading_SimpleMetadataReader.o

$(TARGET):$(OBJS)
	$(CC) $(LIBLINK) -o $(TARGET) $(OBJS)

decrypt.o: decrypt.cpp
	$(CC) $(INCLUDEDIR) -c decrypt.cpp

com_seassoon_encrypt_Decrypt.o: com_seassoon_encrypt_Decrypt.cpp com_seassoon_encrypt_Decrypt.h
	$(CC) $(INCLUDEDIR) -c com_seassoon_encrypt_Decrypt.cpp

org_springframework_core_LocalVariableTableParameterNameDiscoverer.o: org_springframework_core_LocalVariableTableParameterNameDiscoverer.cpp org_springframework_core_LocalVariableTableParameterNameDiscoverer.h
	$(CC) $(INCLUDEDIR) -c org_springframework_core_LocalVariableTableParameterNameDiscoverer.cpp
	
org_springframework_core_type_classreading_SimpleMetadataReader.o: org_springframework_core_type_classreading_SimpleMetadataReader.cpp org_springframework_core_type_classreading_SimpleMetadataReader.h
	$(CC) $(INCLUDEDIR) -c org_springframework_core_type_classreading_SimpleMetadataReader.cpp
			
.PHONY:clean
clean:
	rm $(TARGET) $(OBJS)
