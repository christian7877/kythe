#include "kythe/testdata/indexers/proto/testdata3.pb.h"

//- P3=vname("",_, "", "kythe/testdata/indexers/proto/testdata3.proto","") generates H3=vname("", _, "bazel-out/bin", "kythe/testdata/indexers/proto/testdata3.pb.h", "")
//- P3A=vname("",_, "", "kythe/testdata/indexers/proto/testdata3a.proto","") generates H3A=vname("", _, "bazel-out/bin", "kythe/testdata/indexers/proto/testdata3a.pb.h", "")
//- P3B=vname("",_, "", "kythe/testdata/indexers/proto/testdata3b.proto","") generates H3B=vname("", _, "bazel-out/bin", "kythe/testdata/indexers/proto/testdata3b.pb.h", "")

// Verify that each .pb.h is generated by exactly the corresponding proto
//- !{ P3B generates H3 }
//- !{ P3B generates H3A }
//- !{ P3A generates H3 }
//- !{ P3A generates H3B }
//- !{ P3 generates H3A }
//- !{ P3 generates H3B }
void fn() {
    using namespace ::pkg::proto3;

    //- @Container ref CxxContainerMessage
    Container msg;

    //- @contained ref CxxGetContainedField
    msg.contained();

    //- @contained2 ref CxxGetContained2Field
    msg.contained2();
}
//- ContainerMessageField generates CxxGetContainedField
//- Container2MessageField generates CxxGetContained2Field
//- ContainerMessage generates CxxContainerMessage
