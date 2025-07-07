CXX = g++
CXXFLAGS = -std=c++11 -Isrc/include
LDFLAGS =

SRCDIR = src/src
OBJDIR = obj
BINDIR = .

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
TARGET = estoque_app.exe

all: $(TARGET)

$(TARGET): $(OBJECTS)
	if not exist $(BINDIR) mkdir $(BINDIR)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	if not exist $(OBJDIR) mkdir $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-if exist $(OBJDIR) rmdir /s /q $(OBJDIR)
	-if exist $(TARGET) del $(TARGET)

.PHONY: all clean