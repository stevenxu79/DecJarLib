ifeq ($(shell uname), Linux)
  CC         = g++ -fPIC 
  LIBLINK    = -shared 
  INCLUDEDIR = -I /opt/jdk1.8.0_121/include -I /opt/jdk1.8.0_121/include/linux
  TARGET     = liblibDecJarLib.so
endif

ifeq ($(shell uname), Darwin)
  CC		 = g++ 
  LIBLINK    = -dynamiclib
  TARGET     = libdecrypt.dylib
  INCLUDEDIR = -I/System/Library/Frameworks/JavaVM.framework/Headers
endif

OBJS = decrypt.o com_seassoon_encrypt_Decrypt.o org_springframework_core_LocalVariableTableParameterNameDiscoverer.o org_springframework_core_type_classreading_SimpleMetadataReader.o org_hibernate_boot_archive_scan_spi_ClassFileArchiveEntryHandler.o

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

org_hibernate_boot_archive_scan_spi_ClassFileArchiveEntryHandler.o: org_hibernate_boot_archive_scan_spi_ClassFileArchiveEntryHandler.cpp org_hibernate_boot_archive_scan_spi_ClassFileArchiveEntryHandler.h
	$(CC) $(INCLUDEDIR) -c org_hibernate_boot_archive_scan_spi_ClassFileArchiveEntryHandler.cpp
				
.PHONY:clean
clean:
	rm $(TARGET) $(OBJS)
