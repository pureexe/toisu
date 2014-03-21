void boundaryFill(int x,int y,int fillColor,int borderColor){
    int interiorColor = getPixel(x,y);
    if((interiorColor!=borderColor)&&(interiorColor!=fillColor)){
        setPixel(x,y,fillColor);
        boundaryFill(x+1,y,fillColor,borderColor);
        boundaryFill(x-1,y,fillColor,borderColor);
        boundaryFill(x,y+1,fillColor,borderColor);
        boundaryFill(x,y-1,fillColor,borderColor);
    }
}
