#include <uORB/topics/actuator_position.h>

class MavlinkStreamActuatorPosition : public MavlinkStream
{
public:
    static MavlinkStream *new_instance(Mavlink *mavlink)
    {
        return new MavlinkStreamActuatorPosition(mavlink);
    }

    const char *get_name() const override
    {
        return get_name_static();
    }

    static const char *get_name_static()
    {
        return "ACTUATOR_POSITION";
    }

    static uint16_t get_id_static()
    {
        return MAVLINK_MSG_ID_ACTUATOR_POSITION;
    }

    uint16_t get_id() override
    {
        return get_id_static();
    }

    unsigned get_size() override
    {
        return MAVLINK_MSG_ID_ACTUATOR_POSITION_LEN + MAVLINK_NUM_NON_PAYLOAD_BYTES;
    }

private:
    uORB::Subscription _actuator_position_sub{ORB_ID(actuator_position)};

    // Prevent copying
    MavlinkStreamActuatorPosition(const MavlinkStreamActuatorPosition &) = delete;
    MavlinkStreamActuatorPosition &operator=(const MavlinkStreamActuatorPosition &) = delete;

protected:
    explicit MavlinkStreamActuatorPosition(Mavlink *mavlink) : MavlinkStream(mavlink) {}

    bool send() override
    {
        actuator_position_s actuator_position{};
        bool updated = false;

        // Update from uORB subscription
        if (_actuator_position_sub.update(&actuator_position)) {
            mavlink_actuator_position_t msg{};

	    msg.da   = actuator_position.positions[0];
            msg.de   = actuator_position.positions[1];
            msg.dr   = actuator_position.positions[2];
            msg.dt   = actuator_position.positions[3];
            msg.rpm1 = actuator_position.positions[4];
            msg.rpm2 = actuator_position.positions[5];
            msg.rpm3 = actuator_position.positions[6];
            msg.rpm4 = actuator_position.positions[7];
            msg.rpm5 = actuator_position.positions[8];
            msg.rpm6 = actuator_position.positions[9];
            msg.rpm7 = actuator_position.positions[10];
            msg.rpm8 = actuator_position.positions[11];


            // Send MAVLink message
            mavlink_msg_actuator_position_send_struct(_mavlink->get_channel(), &msg);
            updated = true;
        }

        return updated;
    }
};
