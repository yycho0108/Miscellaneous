def reward(state, action):
        params = {
                'reward_correct' : 2.0,
                'reward_legal' : 0.5,
                'reward_illegal' : -1.0,
                'reward_none' : 1.0
                }

        light = state['light'] 
        waypoint = state['waypoint']

        reward = 0  # reward/penalty
        move_okay = True

        if action == 'forward':
            if light != 'green':
                move_okay = False
        elif action == 'left':
            if light == 'green':
                pass
            else:
                move_okay = False
        elif action == 'right':
            pass

        if action is not None:
            if move_okay:
                reward = params['reward_correct'] if action == waypoint else params['reward_legal']
            else:
                reward = params['reward_illegal']
        else:
            reward = params['reward_none']
        return reward

state = {
        'light': 'green',
        'oncoming': None,
        'right': 'right',
        'waypoint': 'forward',
        'left': None
        };

action = None

print reward(state,action)
