#pragma once

#include <string>
#include <memory>

#include "paddle.h"
#include "../../controllers/controller.h"
#include "../../../modules/network.h"

class PaddleNetworkController : public Controller
{
    public:
        volatile Paddle* paddle_left;
        volatile Paddle* paddle_right;

		~PaddleNetworkController();

        typedef enum class paddle_action 
        {
            BROADCAST,
            CONTROL,
            NONE
        } paddle_action_t;

        void setRightPaddle(Paddle* paddle, paddle_action_t action = paddle_action_t::NONE);
        void setRightPaddleAction(paddle_action_t action);

        void setLeftPaddle(Paddle* paddle, paddle_action_t action);
        void setLeftPaddleAction(paddle_action_t action);

        int update();
        int initialize();
        void onMessage();

    private:
        paddle_action_t paddle_left_action = paddle_action_t::NONE;
        paddle_action_t paddle_right_action = paddle_action_t::NONE;
		std::function<void()>* message_listener_function;
        bool connected = false;
		int location_ping_timer = 0;
		std::shared_ptr<std::string> message;
		/*The number of frames before pinging the server*/
		const int location_ping_time = 4;
        void beginTransmission();
};

