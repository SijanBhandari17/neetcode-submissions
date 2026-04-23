impl Solution {
    pub fn find_duplicate(mut array: Vec<i32>) -> i32 {
  let mut count =0;
      while count<array.len(){
              let fe = array[0];
                      if fe == array[fe as usize]{
                                  return fe;
                                          }else{
                                                      array.swap(0,fe as usize);
                                                              }
                                                                      count+=1;
                                                                          }
                                                                              0
    }
}
