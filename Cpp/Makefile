ALLTARGETS = exampleOptions exectueterminal functions_pointers
TARGET = functions_pointers
OBJS = $(TARGET).o

%.o: %.c
	$(COMPILE) -c $< -o $@
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all: $(ALLTARGETS)
clean:
	rm -f $(OBJS) $(TARGET)
