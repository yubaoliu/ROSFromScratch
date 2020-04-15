#ifndef _MESSAGE_FILTER_H_
#define _MESSAGE_FILTER_H_

#include <image_transport/image_transport.h>
#include <image_transport/subscriber_filter.h>
#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/synchronizer.h>
#include <sensor_msgs/Image.h>

typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Image, sensor_msgs::Image> MySyncPolicy;

class MSG_FILTER {
public:
    // boost::shared_ptr<ros::NodeHandle> m_nh;
    ros::NodeHandle m_nh;
    boost::shared_ptr<message_filters::Synchronizer<MySyncPolicy> > m_sync;

    // boost::shared_ptr<message_filters::Subscriber<sensor_msgs::Image> > image1_sub;
    // boost::shared_ptr<message_filters::Subscriber<sensor_msgs::Image> > image2_sub;

    std::shared_ptr<image_transport::ImageTransport> image_transport_;
    image_transport::SubscriberFilter m_rgb_sub;
    image_transport::SubscriberFilter m_depth_sub;

public:
    MSG_FILTER(const ros::NodeHandle& nh)
    {
        m_nh = nh;

        image_transport_.reset(new image_transport::ImageTransport(m_nh));

        // image1_sub.reset(new message_filters::Subscriber<sensor_msgs::Image>(m_nh, "/camera/rgb/image_color", 1));
        // image2_sub.reset(new message_filters::Subscriber<sensor_msgs::Image>(m_nh, "/camera/depth/image", 1));

        m_rgb_sub.subscribe(*image_transport_, "/camera/rgb/image_color", 1);
        m_depth_sub.subscribe(*image_transport_, "/camera/depth/image", 1);

        // ApproximateTime takes a queue size as its constructor argument, hence MySyncPolicy(10)
        m_sync.reset(new message_filters::Synchronizer<MySyncPolicy>(MySyncPolicy(10), 
                    m_rgb_sub, 
                    m_depth_sub));

        // m_sync->registerCallback(boost::bind(&MSG_FILTER::callback, this, _1, _2));
        m_sync->registerCallback(&MSG_FILTER::callback, this);
    }

    ~MSG_FILTER() {}

    void callback(const sensor_msgs::ImageConstPtr& image1, const sensor_msgs::ImageConstPtr& image2)
    {
        // Solve all of perception here...
        std::cout << "Callback" << std::endl;
    }
};

#endif
