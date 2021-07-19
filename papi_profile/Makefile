BIN=example

all: profile_example.cpp
	$(CXX) $< -o $(BIN) -I/usr/local/include -lpapi

run:
	@# New high-level API since 2019
	@# PAPI_REPORT=1 PAPI_EVENTS="PAPI_L3_TCA,PAPI_L3_TCM" PAPI_OUTPUT_DIRECTORY="here" ./$(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)
