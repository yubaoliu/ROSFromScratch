#include <action_example/DoDishesAction.h> // Note: "Action" is appended
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<action_example::DoDishesAction> Client;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "do_dishes_client");
    Client client("do_dishes", true); // true -> don't need ros::spin()
    client.waitForServer();
    action_example::DoDishesGoal goal;
    goal.dishwasher_id = 1;
    // Fill in goal here
    client.sendGoal(goal);

    client.waitForResult(ros::Duration(5.0));
    if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        printf("Yay! The dishes are now clean");
    printf("Current State: %s\n", client.getState().toString().c_str());

    std::cout << "Result: " << client.getResult()->total_dishes_cleaned << std::endl;

    return 0;
}