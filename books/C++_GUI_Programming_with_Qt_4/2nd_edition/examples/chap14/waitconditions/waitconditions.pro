TEMPLATE = app

CONFIG += console thread

HEADERs = globals.h \
          producer.h \
          consumer.h

SOURCES = globals.cpp \
          producer.cpp \
          consumer.cpp \
          main.cpp
