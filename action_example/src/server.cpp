#include <action_example/DoDishesAction.h> // Note: "Action" is appended
#include <actionlib/server/simple_action_server.h>

typedef actionlib::SimpleActionServer<action_example::DoDishesAction> Server;

void execute(const action_example::DoDishesGoalConstPtr &goal, Server *as) // Note: "Action" is not appended to DoDishes here
{
    // Do lots of awesome groundbreaking robot stuff here
    int id = goal->dishwasher_id;

    action_example::DoDishesResult actionResult;
    actionResult.total_dishes_cleaned = id * 2;

    as->setSucceeded(actionResult);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "do_dishes_server");
    ros::NodeHandle n;
    Server server(n, "do_dishes", boost::bind(&execute, _1, &server), false);
    server.start();
    ros::spin();
    return 0;
}