#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <uxr/client/transport.h>
#include <rmw_microxrcedds_c/config.h>
#include <rmw_microros/rmw_microros.h>
#include <std_msgs/msg/int32.h>

extern "C" void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    //todo: check which pin generated INT
}

extern "C" void bfuMain(void) {
    rcl_publisher_t publisher;
    std_msgs__msg__Int32 msg;
    rclc_support_t support;
    rcl_allocator_t allocator;
    rcl_node_t node;

    allocator = rcl_get_default_allocator();

    rclc_support_init(&support, 0, NULL, &allocator);
    rclc_node_init_default(&node, "cubemx_node", "", &support);

    rclc_publisher_init_default(
        &publisher,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
        "cubemx_publisher");

    msg.data = 0;

    for(;;)
    {
        rcl_ret_t ret = rcl_publish(&publisher, &msg, NULL);
        if (ret != RCL_RET_OK)
        {
            printf("Error publishing (line %d)\n", __LINE__);
        }

        msg.data++;
        osDelay(10);
    }
}
