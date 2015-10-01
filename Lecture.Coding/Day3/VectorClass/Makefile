SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=obj/%.o)

CXXFLAGS := -std=c++11 -g -c

program : $(OBJS)
	$(CXX) $(OBJS) -o $@

obj/%.o : %.cpp | obj
	$(CXX) $(CXXFLAGS) $< -o $@

obj :
	@mkdir -p obj

clean :
	@rm obj/*.o program
