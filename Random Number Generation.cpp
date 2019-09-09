

// Throwing dice.
// Mersenne Twister.
boost::random::mt19937 myRng;

// Set the seed.
myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

// Uniform in range [1,6]
boost::random::uniform_int_distribution<int> six(1,6);

map<int, long> statistics; // Structure to hold outcome + frequencies
int outcome; // Current outcome

outcome = six(myRng);
