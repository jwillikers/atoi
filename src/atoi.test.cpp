#include <boost/ut.hpp>
#include <string_view>
#include "atoi.h"

int main() {
    using namespace boost::ut;

    "should_return_zero_given_empty_string"_test = [] {
        constexpr std::string_view s{};
        expect(0_i == my_atoi(s.data()));
    };

    "should_return_zero_given_null_pointer"_test = [] {
        expect(0_i == my_atoi(nullptr));
    };

    "should_parse_one"_test = [] {
        constexpr std::string_view s{"1"};
        expect(1_i == my_atoi(s.data()));
    };

    "should_parse_one_preceded_by_a_plus_sign"_test = [] {
        constexpr std::string_view s{"+1"};
        expect(1_i == my_atoi(s.data()));
    };

    "should_parse_negative_one"_test = [] {
        constexpr std::string_view s{"-1"};
        expect(-1_i == my_atoi(s.data()));
    };

    "should_parse_twelve"_test = [] {
        constexpr std::string_view s{"12"};
        expect(12_i == my_atoi(s.data()));
    };

    "should_parse_twelve_thousand"_test = [] {
        constexpr std::string_view s{"1200"};
        expect(1200_i == my_atoi(s.data()));
    };

    "should_parse_integer_portion_of_a_floating_point_number"_test = [] {
        constexpr std::string_view s{"1.2"};
        expect(1_i == my_atoi(s.data()));
    };

    "should_parse_zero"_test = [] {
        constexpr std::string_view s{"0"};
        expect(0_i == my_atoi(s.data()));
    };

    "should_parse_negative_zero"_test = [] {
        constexpr std::string_view s{"-0"};
        expect(-0_i == my_atoi(s.data()));
    };

    "should_parse_digits_until_first_non_digit_character"_test = [] {
        constexpr std::string_view s{"123abc"};
        expect(123_i == my_atoi(s.data()));
    };
}