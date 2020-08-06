#include"Graph.h"
Graph::Graph(Rubik_cube rc,size_t r , size_t d )
{
	this->limit = d;
	this->F = r;
	this->rv.push_back(rc);
	this->deapth.push_back(0);
	rc.show();
	
    //to check if the input rubik is right or not
	NumbeofNodes++;
	if (rc.Goal_test())
	{
		std::cout << "We checked : " << NumbeofNodes<< "Nodes " <<std::endl;
		rc.show();

	}	
	Rubik_cube current{ rv[rv.size() - 1] };
	this->rv.pop_back();
	this->deapth.pop_back();
	temp++;
	current.Rotate(r, 1);

	outPTemp.push_back(r);
	outPTemp.push_back(1);
	outP.push_back(outPTemp);
	outPTemp.pop_back();
	outPTemp.pop_back();

	NumbeofNodes++;
	this->rv.push_back(current);
	this->deapth.push_back(temp);
	current.Rotate(r, 0);
	current.Rotate(r, 0);
	NumbeofNodes++;
	this->rv.push_back(current);
	this->deapth.push_back(temp);

	outPTemp.push_back(r);
	outPTemp.push_back(0);
	outP.push_back(outPTemp);
	outPTemp.pop_back();
	outPTemp.pop_back();

}
/*<---------------------------------------------------------------------------------------------------------------------------------->*/
bool Graph::DLS()
{
	Rubik_cube current{ rv[rv.size() - 1] };
	size_t D{ deapth[deapth.size() - 1] };
    //till the stack is full or the answer get finded this while keep on working
	while (rv.size()!= 0)
	{
		
		current = rv[rv.size() - 1];
		D = deapth[deapth.size() - 1];
		this->rv.pop_back();
		this->deapth.pop_back();
		if (current.Goal_test())
		{
				std::cout << "it did get fixed" << std::endl;
				std::cout << "We checked : " << NumbeofNodes<< "Nodes " <<std::endl;
				current.show();
				navigaiton();
				return true;
		}
		else if (D<limit)
		{
			outP.pop_back();
			temp++;
			for (size_t i = 1; i < 4; i++)
			{
                //get childeran of this parent 
				current.Rotate(i, 1);
				NumbeofNodes++;
				this->rv.push_back(current);
				this->deapth.push_back(temp);

				outPTemp.push_back(i);
				outPTemp.push_back(1);
				outP.push_back(outPTemp);
				outPTemp.pop_back();
				outPTemp.pop_back();

				current.Rotate(i, 0);
				current.Rotate(i, 0);
				NumbeofNodes++;
				this->rv.push_back(current);
				this->deapth.push_back(temp);

				outPTemp.push_back(i);
				outPTemp.push_back(0);
				outP.push_back(outPTemp);
				outPTemp.pop_back();
				outPTemp.pop_back();

                //and back to deafult values 
				current.Rotate(i, 1);

			}
		}
		while (D == limit)
		{
			
			if (rv.size() == 0)
			{
                //for going to anticolck zone there is rv.size()=0 that makes a probelem this is how to handle it 
				rc.Rotate(F, 1);
				this->rv.push_back(rc);
				this->deapth.push_back(1);
				rc.Rotate(F, 0);
				break;
			}
			
			else 
			{
				current = rv[rv.size() - 1];
				D = deapth[deapth.size() - 1];
				this->rv.pop_back();
				this->deapth.pop_back();
				
				if (current.Goal_test())
				{
					std::cout << "it did get fixed" << std::endl;
					std::cout << "We checked : " << NumbeofNodes<< "Nodes " <<std::endl;
					current.show();
					navigaiton();
					return true;
				}
				else if (D < limit)
				{
					outP.pop_back();
                    //to go up in stack
					temp = D;
					//break;
				}
			}

		}
	}
	if(!current.Goal_test())
	{
		std::cout<<"it was not fixable"<<std::endl;
		return false;
	}
	else
	{
		navigaiton();
		return true;
	}
	
	
}
/*<---------------------------------------------------------------------------------------------------------------------------------->*/
void Graph::navigaiton()
{
	for (size_t j =  outP.size()-1 ; j > outP.size()-limit-1 ; j--)
		{
			if(outP[j][1]==0)
			{
				std::cout<<outP[j][0]<<"  "<<"colckwise"<<std::endl;
			}
			else if(outP[j][1]==1)
			{
				std::cout<<outP[j][0]<<"  "<<"anticolckwise"<<std::endl;
			}
		}
}
void Graph::IDS(size_t input)
{
	for (size_t i = 1; i < input; i++)
	{
		if(!DLS())
		{
			limit=i;
		}
		else
		{
			break;
		}
		

	}
	
}