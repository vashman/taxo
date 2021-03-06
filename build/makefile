CC=/usr/bin/g++
FLAGS=-g -fno-rtti -std=c++11 -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

BIN=./bin
SRC=../src
EXDIR=../example
OBJS=$(BIN)/objs
EXOBJ=$(OBJS)/example
LIBS=$(BIN)/libs

# install dirs
INCDIR=/usr/local/include/taxo
LIBDIR=/usr/local/lib

SOURCES=$(wildcard $(SRC)/*.cpp)
OBJECTS=$(patsubst %, $(OBJS)/%, $(notdir $(SOURCES:%.cpp=%.o)))

# examples
EXSRC=$(wildcard $(EXDIR)/*.cpp)
EXOBJS=$(patsubst %, $(EXOBJ)/%, $(notdir $(EXSRC:%.cpp=%.o)))
EXAMPLES=$(patsubst %, $(BIN)/%, $(notdir $(EXSRC:%.cpp=%)))

MAJOR=0
MINOR=0
LIB=libtaxo.so
DLIB=$(LIBS)/libtaxo.so.$(MAJOR).$(MINOR)
SLIB=$(LIBS)/libtaxo.a.$(MAJOR).$(MINOR)

.PHONY: clean all dirs lib example

$(OBJS)/%.o: $(SRC)/%.cpp
	$(CC) -o $@ -c $< -fPIC $(FLAGS) 2> object.log

$(EXOBJ)/%.o: $(EXDIR)/%.cpp
	$(CC) -c $< -o $@ $(FLAGS) 2> example_object.log

$(BIN)/%: $(EXOBJ)/%.o
	$(CC) $< -o $@ $(FLAGS) $(SLIB) 2> example.log

define cc-lib_dynamic
$(CC) $^ -shared $(FLAGS) -o $@ 2> dyncamiclib.log
endef

define cc-lib_static
ar rvs $@ $^ 2> staticlib.log
endef

all: dirs $(SLIB) $(DLIB) $(EXAMPLES)

$(SLIB): $(OBJECTS)
	$(cc-lib_static)

$(DLIB): $(OBJECTS)
	$(cc-lib_dynamic)

$(OBJECTS): $(SOURCES)

# Writer
$(EXAMPLES): $(EXOBJS)

$(EXOBJS): $(EXSRC)

clean:
	rm -rf $(BIN)
	rm ./*.log

dirs:
	mkdir -p $(BIN)
	mkdir -p $(OBJS)
	mkdir -p $(LIBS)
	mkdir -p $(EXOBJ)

lib: $(SLIB) $(DLIB)

install: $(DLIB)
	mkdir -p -m  655 $(INCDIR)
	install -c  $(DLIB) $(LIBDIR)
	ldconfig -v -n $(LIBDIR)
	ln -sf $(LIBDIR)/$(LIB).$(MAJOR).$(MINOR) $(LIBDIR)/$(LIB).$(MAJOR)
	ln -sf $(LIBDIR)/$(LIB).$(MAJOR) $(LIBDIR)/$(LIB)
	cp -r ../include/* $(INCDIR)

remove: $(LIBDIR)/$(LIB) $(INCDIR)
	rm -r $(INCDIR)
	rm $(LIBDIR)/$(LIB)*
