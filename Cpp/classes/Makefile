CXXFLAGS =	-g -Wall -fmessage-length=0

OBJS =		init_array.o Conformation.o

LIBS = -lm

TARGET =	init_array

%.o: %.c
	$(COMPILE) -c $< -o $@

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

