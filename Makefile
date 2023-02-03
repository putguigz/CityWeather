TARGET=CityWeather

CXX=clang++
CXXFLAGS=-Wall -Wextra -Werror -g3
CPPFLAGS=-Iincludes
LIBCURLPP=-Llib64 -lcurl -lcurlpp

SRC_DIR=srcs
OBJ_DIR=objs

SRC=$(wildcard $(SRC_DIR)/*.cpp)
OBJ=$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $@

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LIBCURLPP)

clean: 
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(TARGET)

re: fclean all