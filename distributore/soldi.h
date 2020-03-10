#ifndef SOLDI_H
#define SOLDI_H


class soldi
{
public:
  double valore;
   virtual double getValore() const = 0;
   virtual ~soldi()=0;
};

class soldiFisici: virtual public soldi{

};

class soldiVirtuali: virtual public soldi{

};

#endif // SOLDI_H
