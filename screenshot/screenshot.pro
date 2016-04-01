TARGET = screenshot
HEADERS = screenShotWindow.h \
          fullScreenWidget.h

SOURCES = main.cpp \ 
          screenShotWindow.cpp \
          fullScreenWidget.cpp 

DESTDIR = ./bin

#temp-directory sources
OBJECTS_DIR = ./.objtmp
MOC_DIR = ./.moctmp
UI_DIR  += ./.uitmp
