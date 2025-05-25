#include <SignalProcessing/fir-filters/RationalResamplingFIR.hpp>
#include <gtest/gtest.h>

#include <cstdint>
#include <memory>
#include <type_traits>
#include <utility>

namespace {

}; // namespace

using TDataTypeList = testing::Types<float>;

template <class>
struct CanvasViewTest : testing::Test
{
};

TYPED_TEST_SUITE(CanvasViewTest, TDataTypeList);

TYPED_TEST(CanvasViewTest, RationalResamplingFIR_Example)
{
  SignalProcessing::fir_filters::RationalResamplingFIR();
}
