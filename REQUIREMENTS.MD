# REQUIREMENTS

- Shall collect barometric data from BMP 2080
- Shall accumulate data for future downlink
- Shall downlink data with controlled priority
- Shall be able to run on the raspberry pi
- Shall read the BPM280 sensor at 10hz

## Data Requirements
- Each data sample shall contain inmmediate pressure, temperature and altitude data with timestamp of when it was meassured
	- Preassure measurements shall be expressed in pascals
	- Temperature meassurements shall be expressed in celcius
	- Altitude data meassurements shall be expressed in meters
	- Timestamps must be stored in UTC Unix timestamps in millseconds
- Each data deliverable to the ground station shall contain exactly 10, non repeating samples

## Code Requirements

- Shall include the fprime-sensors library
- Shall have a component for BMP 2080
    - Shall preallocate buffer for collected data
    - Shall serialize data for downlink
- Shall have a container for serialized BMP data
- Shall have a component for downlinking serialized BMP data from container
- Shall use GDS for receiving and decoding BMP data (TBD)

## Component Functional Requirements

- All sample values shall be stored in big endian format
- Samples shall be stored on an FPrime Data Product container
- Each data product  container shall contain a maxium of 100 samples
- Each data sample shall contain data in the following order:
	1. Timestamp
	2. Temperature
	3. Altitude
	4. Preassure
- The timestamp filed on any data sample shall be stored as a 64 bit unsigned integer
- The temperature filed on any data sample shall be stored as a 32 bit floating point number
- The altitude filed on any data sample shall be stored as a 32 bit floating point number
- The preassure filed on any data sample shall be stored as a 32 bit floating point number
