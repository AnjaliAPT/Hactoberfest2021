import java.util.*;
class ParkingSystemDesign
{
     int addressFill=1;
    static Map<String,Integer> carParkedAddress=new HashMap<>();  // store with  plateNumber with address if it contains -1-
    static Queue<Integer> smallque=new LinkedList<>();                 // for small garage address 
    static Queue<Integer> mediumque=new LinkedList<>();                // for medium garage address 
    static Queue<Integer> largeque=new LinkedList<>();                 // for large garage address 
    static Map<String,Integer> smallsizestoredinmedium=new HashMap<>();             // small car stored in medium
    static Map<String,Integer> smallsizestoredinLarge=new HashMap<>();              // small car stored in large
   static  Map<String,Integer> mediumsizestoredinLarge=new HashMap<>();           //medium car stored in large
   
    ParkingSystemDesign(int small,int medium,int large)
    {
         for(int i=0;i<small;i++)
        {
            smallque.add(addressFill++);
        }
         for(int i=0;i<medium;i++)
        {
             mediumque.add(addressFill++);
        }
         for(int i=0;i<large;i++)
        {
             largeque.add(addressFill++);
        }
    }
    public static void parkYourVehicle(String plateNumber,String type)
    {
        if(type.equals("small"))
        {
            if(!smallque.isEmpty())    // small store in its own address 
            {
                int tempAddress=smallque.poll();
                carParkedAddress.put(plateNumber,tempAddress);
            }
            else if(!mediumque.isEmpty())          // small store in medium address 
            {
                 int tempAddress=mediumque.poll();
                 smallsizestoredinmedium.put(plateNumber,tempAddress);
                 carParkedAddress.put(plateNumber,-1); // -1 means its store  medium section
            }
            else if(!largeque.isEmpty())             // small store in large address 
            {
                int tempAddress=largeque.poll();
                smallsizestoredinLarge.put(plateNumber,tempAddress);
                carParkedAddress.put(plateNumber,-2);  // -2 means its store  large  section
            }
            else
            {
                System.out.println("Sorry we dont have a space for small Car");
            }
        }
        else if(type.equals("medium"))
        {
            if(!mediumque.isEmpty())
            {
                int tempAddress=mediumque.poll();
                carParkedAddress.put(plateNumber,tempAddress);
            }
            else if(!smallque.isEmpty() && smallsizestoredinmedium.size()>0)
            {
                Map.Entry<String,Integer>entry=smallsizestoredinmedium.entrySet().iterator().next();
                String key=entry.getKey();
                Integer value=entry.getValue();
                exit(key,"small");
                parkYourVehicle(key,"small");
                parkYourVehicle(plateNumber,type);
            }
             else if(!smallque.isEmpty() && smallsizestoredinLarge.size()>0)
            {
                Map.Entry<String,Integer>entry=smallsizestoredinLarge.entrySet().iterator().next();
                String key=entry.getKey();
                Integer value=entry.getValue();
                exit(key,"small");
                parkYourVehicle(key,"small");
                parkYourVehicle(plateNumber,type);
            }
            else if(!largeque.isEmpty())
            {
                int tempAddress=largeque.poll();
                mediumsizestoredinLarge.put(plateNumber,tempAddress);
                carParkedAddress.put(plateNumber,-3); // -3 means its store  large  section
            }
            else
            {
                System.out.println("Sorry we dont have a space for medium Car");
            }
        }
        else
        {
            if(!largeque.isEmpty())
            {
                int tempAddress=largeque.poll();
                carParkedAddress.put(plateNumber,tempAddress);
            }
            else if(smallsizestoredinLarge.size()>0&&!smallque.isEmpty())
            {
                 Map.Entry<String,Integer>entry=smallsizestoredinLarge.entrySet().iterator().next();
                String key=entry.getKey();
                Integer value=entry.getValue();
                exit(key,"small");
                parkYourVehicle(key,"small");
                parkYourVehicle(plateNumber,type);
            }
            else if(mediumsizestoredinLarge.size()>0&&!mediumque.isEmpty())
            {
                 Map.Entry<String,Integer>entry=mediumsizestoredinLarge.entrySet().iterator().next();
                String key=entry.getKey();
                Integer value=entry.getValue();
                exit(key,"medium");
                parkYourVehicle(key,"medium");
                parkYourVehicle(plateNumber,type);
            }
            else if(mediumsizestoredinLarge.size()>0&&smallsizestoredinmedium.size()>0&&!smallque.isEmpty())
            {
                System.out.println("ashish");
                 Map.Entry<String,Integer>entry=smallsizestoredinmedium.entrySet().iterator().next();
                String key=entry.getKey();
                Integer value=entry.getValue();
                exit(key,"small");
                parkYourVehicle(key,"small");
              
                Map.Entry<String,Integer>entry1=mediumsizestoredinLarge.entrySet().iterator().next();
                String key1=entry1.getKey();
                Integer value1=entry1.getValue();
                exit(key1,"medium");
                parkYourVehicle(key1,"medium");
                parkYourVehicle(plateNumber,type);
            }
            else
            {
                System.out.println("Sorry we dont have a space for Large Car");
            }
        }
    }
     public static int  exit(String plateNumber,String type)                          // give platnumber it will give you address;
     {
         int result=Integer.MAX_VALUE;
         if(carParkedAddress.containsKey(plateNumber))
         {
             int address=carParkedAddress.get(plateNumber);
             carParkedAddress.remove(plateNumber); 
             if(address==-1)                                                // small car stored in medium section
             {
                 int addressWhereCarStored=smallsizestoredinmedium.get(plateNumber);
                 mediumque.add(addressWhereCarStored);                                    // space add again in medium queue
                 smallsizestoredinmedium.remove(plateNumber);                              // remove key value from  smallsizestoredinmedium map
                 result=addressWhereCarStored;                                               // get address of car 
             }
             else if(address==-2)                                           // small car stored in Large section
             {
                 int addressWhereCarStored=smallsizestoredinLarge.get(plateNumber);        // get address of car 
                 largeque.add(addressWhereCarStored);                                    // space add again in Large queue
                 smallsizestoredinLarge.remove(plateNumber);                            // remove key value from  smallsizestoredinmedium map
                 result=addressWhereCarStored;
                 
             }
              else if(address==-3)                                          // medium car  stored in large section
             {
                 int addressWhereCarStored=mediumsizestoredinLarge.get(plateNumber);    // get address of car 
                 largeque.add(addressWhereCarStored);                                   // add space again in large queue
                 mediumsizestoredinLarge.remove(plateNumber);                           // remove key value from mediumsizestoredinLarge map
                 result=addressWhereCarStored;
             }
             else
             {
                 if(type.equals("small"))
                 {
                    smallque.add(result); 
                 }
                 else if (type.equals("small"))
                 {
                     mediumque.add(result);  
                 }
                 else
                 {
                      largeque.add(result); 
                 }
                 
             }
             System.out.println("car remove ");
         }
         else
         {
             System.out.println("Not Present");
         }
         return result;
     }
	public static void main (String[] args) 
	{
	    Scanner sc=new Scanner(System.in);
	    int smallSpot=sc.nextInt();
	    int mediumSpot=sc.nextInt();
	    int largeSpot=sc.nextInt();
	    ParkingSystemDesign obj=new  ParkingSystemDesign(smallSpot,mediumSpot,largeSpot);
	    ArrayList<String> array=new ArrayList<>();
	    array.add("qwe123 small");
	    array.add("qwe456 small");
	    array.add("qwe789 small");
	    array.add("qwe101112 small");
	    array.add("qwe131415 small");
	    array.add("qwe131415 medium");
	    for(int i=0;i<array.size();i++)
	    {
	        String temp[]=array.get(i).split(" ");
	        parkYourVehicle(temp[0],temp[1]);
	    }
	    exit("qwe123","small");
	    System.out.println(mediumsizestoredinLarge.size()+" "+smallsizestoredinmedium.size()+" "+!smallque.isEmpty());
	      parkYourVehicle("hjeee","large");
	    
	    System.out.println(carParkedAddress);
	}
}
