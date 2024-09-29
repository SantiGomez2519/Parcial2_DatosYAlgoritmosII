CXX = g++
CXXFLAGS = -O3 -ftree-vectorize -fopenmp -mavx2
LDFLAGS =

# Intenta usar C++17, si no está disponible, usa C++11
ifeq ($(shell $(CXX) -std=c++17 -E -x c++ - < /dev/null > /dev/null 2>&1 && echo yes),yes)
    CXXFLAGS += -std=c++17
else
    CXXFLAGS += -std=c++11
endif

SRCS = Grafo.cpp Parcial.cpp EvaluarParcial.cpp VecinoMasCercano.cpp
# OBJS = $(SRCS:.cpp=.o)
# DEPS = $(SRCS:.cpp=.d)
TARGET = evaluador

all: $(TARGET)

# $(TARGET): $(OBJS)
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
#	rm -f $(OBJS) $(DEPS) $(TARGET)
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

-include $(DEPS)

.PHONY: all clean run