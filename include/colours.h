class Colour
{
public:
    Colour()
    {
       
    }

    Colour(int _r, int _g, int _b)
    {
        SetColor(_r, _g, _b, 0);
    }
    
    Colour(int _r, int _g, int _b, int _a)
    {
        SetColor(_r, _g, _b, _a);
    }

    void SetColor(int _r, int _g, int _b, int _a = 0)
    {
        _color[0] = (unsigned char)_r;
		_color[1] = (unsigned char)_g;
		_color[2] = (unsigned char)_b;
		_color[3] = (unsigned char)_a;
    }
    
    int getColorInt()
    {
       return ((r() << 16) & 0x00FF0000) | ((g() << 8) & 0x0000FF00) | (b() & 0x000000FF);
    }
    


    unsigned char &operator[](int index)
	{
		return _color[index];
	}

    inline int r() const	{ return _color[0]; }
	inline int g() const	{ return _color[1]; }
	inline int b() const	{ return _color[2]; }
	inline int a() const	{ return _color[3]; }

    ~Colour()
    {
        
    }
private:
    unsigned char _color[4];
};

#define Color Colour // continuity sake for americanos

