CXX = g++
CXXFLAGS += -std=c++1z -Wall -Wno-c++11-extensions -Wno-c++11-narrowing -MMD -iquote./
CXXFLAGS += $(pkg-config --cflags boatcontrol)
LFLAGS +=

BLD = build/
SRCS = $(wildcard *.cpp)
BLDS = $(addprefix $(BLD)/, $(filter %.o, $(notdir $(SRCS:.cpp=.o))))
DEPS = $(addprefix $(BLD)/, $(filter %.d, $(notdir $(SRCS:.cpp=.d))))
TARGET = boatnav

.PHONY: clean

$(TARGET): $(BLDS)
	$(CXX) $(CXXFLAGS) $(LXXFLAGS) $^ -o $@

$(BLD)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean: 
	@rm -f $(BLDS) $(DEPS)
