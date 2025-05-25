#include <SignalProcessing/fir-filters/RationalResamplingFIR.hpp>

#include <cmath>
#include <iostream>

#include <plot.h>

namespace SignalProcessing::fir_filters {
void RationalResamplingFIR()
{
  std::cout << "TODO: Implement the RationalResamplingFIR" << std::endl;

  { // Basic example
    signalsmith::plot::Plot2D plot;

    // Customize the axes
    plot.x.major(0).tick(10).label("time");
    plot.y.major(0).minors(-1, 1).label("signal");

    // Add some data with `.add(x, y)`
    auto &sin = plot.line(), &cos = plot.line();
    for (double x = 0; x < 10; x += 0.01)
    {
      sin.add(x, std::sin(x));
      cos.add(x, std::cos(x));
    }
    sin.label("sin(x)");
    cos.label("cos(x)");

    plot.write("default-2d.svg");
  }
}
} // namespace SignalProcessing::fir_filters
