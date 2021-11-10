#include <iostream>

#include <cppast/cpp_entity.hpp>

#include "test_parser.hpp"

using namespace cppast;
using namespace std;

int do_main() {
    auto code = R"(
		//#include <foundation/Foundation.h>
		#if 1
		#endif
		/// This a comment1
        namespace the_ns {
			/// This a comment2
            class foo {
			public:

				void method();

				/**
				 * This a javadoc
				 */
                enum inner_enum {};
                class bar {};
            };
            class one {}; class two {}; class three {};
            enum quaz {};
        }
        enum outer {};
    )";

    cpp_entity_index idx;
    auto file = parse(idx, "cpp_class.cpp", code);
    unsigned filtered_count = 0;
    auto visitor_callback = [&](const cpp_entity &en, cppast::visitor_info info) {
        if (info.event != cppast::visitor_info::container_entity_exit) {
            ++filtered_count;

            std::cout << std::endl;
            std::cout << to_string(en.kind()) << std::endl;
            std::cout << "Name: " << en.name() << std::endl;
            if (en.comment().has_value()) {
                std::cout << "Comment: " << en.comment().value() << std::endl;
            }
            for (auto &attribute : en.attributes()) {
                std::cout << "" << attribute.name() << std::endl;
            }
        }
        return true;
    };

    constexpr auto all_node_count = 10, enum_count = 3, class_count = 5;

    SECTION("all nodes are visited")
    {
        filtered_count = 0;
        cppast::visit(
                *file, [](const cpp_entity &) { return true; }, visitor_callback);
        REQUIRE(filtered_count == all_node_count);
    }

    return 0;
}

int main() {
    try {
        do_main();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
