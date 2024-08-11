/*
void Signal::MATHGL() const
{
    //Create mglGraph object
    mglGraph gr;

    //MathGL objects from the mglData class for plotting
    mglData x(numSample);
    mglData y(numSample);

    //Copy time and signal samples into mglData objects
    for (unsigned int i = 0; i < numSample; i++)
    {
        x.a[i] = time[i];
        y.a[i] = signal[i];
    }

    //TItl
    gr.Title("Signal Graph");

    gr.SetRanges(x.Minimal(), x.Maximal(), y.Minimal(), y.Maximal());

    gr.SetOrigin(0, 0);

    gr.Axis();

    gr.Plot(x, y);

    std::string first, second;
    first = filename + ".eps";
    second = filename + ".png";

    const char* epsFile = first.c_str();
    const char* pngFile = second.c_str();

    gr.WriteEPS(epsFile);
    gr.WritePNG(pngFile);
}
*/