if BUILD_AV

lib_LTLIBRARIES += librtp.la \
                   libmsi.la \
                   libmedia.la \
                   libtoxav.la

#Someone needs to fix this makefile
VPX_LIBS = -lvpx
                   
# ****** RTP ****** #
                   
librtp_la_include_HEADERS = \
                        ../toxavrtp.h

librtp_la_includedir = $(includedir)/tox

librtp_la_SOURCES =  ../toxav/rtp.h \
                        ../toxav/rtp.c 

librtp_la_CFLAGS = -I../toxcore \
                       -I../toxav \
                       $(NACL_CFLAGS)

librtp_la_LDFLAGS = $(TOXRTP_LT_LDFLAGS) \
                       $(NACL_LDFLAGS) \
                       $(EXTRA_LT_LDFLAGS)

librtp_la_LIBS =    libtoxcore.la \
                       $(NACL_LIBS)
                        
                        
                        
                        
                        
# ****** MSI ****** #

libmsi_la_include_HEADERS = \
                        ../toxav/msi.h

libmsi_la_includedir = $(includedir)/tox

libmsi_la_SOURCES =  ../toxav/msi.h \
                        ../toxav/msi.c 

libmsi_la_CFLAGS = -I../toxcore \
                       -I../toxav \
                       $(NACL_CFLAGS) 

libmsi_la_LDFLAGS = $(TOXMSI_LT_LDFLAGS) \
                       $(EXTRA_LT_LDFLAGS) \
                       $(NACL_LDFLAGS) 

libmsi_la_LIBS =    libtoxcore.la \
                       $(NACL_LIBS)
                        
                        
                        
                        
                        
# ****** MEDIA ****** #

libmedia_la_include_HEADERS = \
                        ../toxav/media.h

libmedia_la_includedir = $(includedir)/tox

libmedia_la_SOURCES =  ../toxav/media.h \
                          ../toxav/media.c 

libmedia_la_CFLAGS =   -I../toxcore \
                          -I../toxav \
                          $(NACL_CFLAGS) \
                          $(OPUS_CFLAGS) 

                          
libmedia_la_LDFLAGS =  $(TOXMSI_LT_LDFLAGS) \
                          $(TOXRTP_LT_LDFLAGS) \
                          $(EXTRA_LT_LDFLAGS) \
                          $(NACL_LDFLAGS) 
                          
                          
libmedia_la_LIBS =     libtoxcore.la \
                          $(NACL_LDFLAGS) \
                          $(NACL_LIBS) \
                          $(OPUS_LIBS) \
                          $(VPX_LIBS)
                          
                          
# ****** TOXAV ****** #

libtoxav_la_include_HEADERS = \
                        ../toxav/toxav.h

libtoxav_la_includedir = $(includedir)/tox

libtoxav_la_SOURCES =  ../toxav/toxav.h \
                          ../toxav/toxav.c 

libtoxav_la_CFLAGS =   -I../toxcore \
                          -I../toxav \
                          $(NACL_CFLAGS) \
                          $(OPUS_CFLAGS) 

                          
libtoxav_la_LDFLAGS =  $(TOXMSI_LT_LDFLAGS) \
                          $(TOXRTP_LT_LDFLAGS) \
                          $(EXTRA_LT_LDFLAGS) \
                          $(NACL_LDFLAGS) 
                          
                          
libtoxav_la_LIBS =     libtoxcore.la \
                          $(NACL_LDFLAGS) \
                          $(NACL_LIBS) \
                          $(OPUS_LIBS) \
                          $(VPX_LIBS)
                          
                          
                          
                                
                          
# ***** PHONE ***** #
                          
noinst_PROGRAMS += phone

phone_SOURCES = ../toxav/phone.c 

phone_CFLAGS = -I../toxcore \
               -I../toxav \
                $(AVFORMAT_CFLAGS) \
                $(AVCODEC_CFLAGS) \
                $(AVUTIL_CFLAGS) \
                $(AVDEVICE_CFLAGS) \
                $(SWSCALE_CFLAGS) \
                $(SDL_CFLAGS) \
                $(OPENAL_CFLAGS) \
                $(NACL_CFLAGS) \
                $(OPUS_CFLAGS) 


phone_LDADD =   librtp.la \
                libmsi.la \
                libmedia.la  \
                libtoxav.la  \
                libtoxcore.la \
                $(NACL_LDFLAGS) \
                $(AVFORMAT_LIBS) \
                $(AVCODEC_LIBS) \
                $(AVUTIL_LIBS) \
                $(AVDEVICE_LIBS) \
                $(SWSCALE_LIBS) \
                $(SDL_LIBS) \
                $(OPENAL_LIBS) \
                $(NACL_LIBS) \
                $(OPUS_LIBS) \
                $(VPX_LIBS)
                
                
endif