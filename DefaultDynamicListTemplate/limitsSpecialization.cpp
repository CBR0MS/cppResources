// overloading the numeric_limts class
// to allow the use of custom classes

#include <limits>

template<> class numeric_limits<ClassName> {

    public:
       static ClassName min() {return ClassName(-234523);};
       static ClassName max() {return ClassName(234523);};
       };
