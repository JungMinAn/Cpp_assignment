CC = g++
TARGET = battleship
SOURCES = Main.cpp \
          CBattleShipApp.cpp \
          CBattleShipMap.cpp \
          Pane.cpp \
          StatPane.cpp \
          InputPane.cpp \
          Ship.cpp
LDFLAGS = -lncursesw
all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf *.o $(TARGET)
