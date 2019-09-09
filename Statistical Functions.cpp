double scaleParameter = 0.5;

// Default type is 'double'
exponential_distribution<> myExponential(scaleParameter);

cout << "Mean:" << mean(myExponential)
<< ",standard deviation: "
<< standard_deviation(myExponential) << endl;
