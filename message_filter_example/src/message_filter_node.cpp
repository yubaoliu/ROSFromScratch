#include  "message_filter.h"

using namespace message_filters;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "vision_node");

    ros::NodeHandle nh;

    boost::shared_ptr<MSG_FILTER> instance(new MSG_FILTER(nh));
    
    ros::spin();

    return 0;
}
