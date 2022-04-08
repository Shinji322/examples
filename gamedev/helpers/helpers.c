int help_sign(float x)
{
    if (x < 0) return -1;
    else if (x < 0.0001) return 0;
    return 1;
}

float help_abs(float x)
{
    if (x < 0.0) x *= -1.0;
    return x;
}

float help_clamp(float value, float min, float max)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}
