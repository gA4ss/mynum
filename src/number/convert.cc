#include <mynum/number/convert.h>

namespace mynum {
namespace number {

mynum_complex_t convert_to_complex(const mynum_number_t& object) { return dyn_cast<Complex>(object); }
Complex* convert_to_complex(Number* object) { return dynamic_cast<Complex*>(object); }
Complex& convert_to_complex(Number& object) { return dynamic_cast<Complex&>(object); }

mynum_real_t convert_to_real(const mynum_number_t& object) { return dyn_cast<Real>(object); }
Real* convert_to_real(Number* object) { return dynamic_cast<Real*>(object); }

mynum_integer_t convert_to_integer(const mynum_number_t& object) { return dyn_cast<Integer>(object); }
Integer* convert_to_integer(Number* object) { return dynamic_cast<Integer*>(object); }

bool is_complex(const mynum_number_t& object) { return object->class_name() == "complex"; }
bool is_complex(Number* object) { return object->class_name() == "complex"; }
bool is_complex(const Number& object) { return object.class_name() == "complex"; }

bool is_real(const mynum_number_t& object) { return object->class_name() == "real"; }
bool is_real(Number* object) { return object->class_name() == "real"; }
bool is_real(const Number& object) { return object.class_name() == "real"; }

bool is_integer(const mynum_number_t& object) { return object->class_name() == "integer"; }
bool is_integer(Number* object) { return object->class_name() == "integer"; }
bool is_integer(const Number& object) { return object.class_name() == "integer"; }

} // namespace number
} // namespace mynum