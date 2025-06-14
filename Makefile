INCLUDES = -I${IDA_INCLUDE_PATH}
LINKS = -L${IDA_LIBRARY_PATH}
LINKS+= -lida -lidalib

CXXFLAGS = -W -Wall -Wextra -pedantic -std=c++20 ${INCLUDES} -fPIC
LDFLAGS = ${LINKS}

SRC=$(wildcard *.cc)
OBJ=${SRC:.cc=.o}
BIN=rtti_recover.so

all: $(BIN)

clean:
	rm -rf $(OBJ) $(BIN)

install:
	cp $(BIN) ${IDA_PLUGINS_DIR}/${BIN}

$(BIN): $(OBJ)
	$(CC) -shared -o $@ $^ $(LINKS)
