void read_initialize();

byte read_particles(float *pm25, float *pm10);


float read_humidity();

float read_temperatureCel();

float read_temperatureFar();

float read_heatIndexCel(float temperature, float humidity);

float read_heatIndexFar(float temperature, float humidity);
