using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyMovement : MonoBehaviour
{
    public float countDown;
    public Animator anim;
    AudioSource shoot;



    // Use this for initialization
    void Start()
    {
        countDown = (20 * Random.value) + 2;
        shoot = GetComponent<AudioSource>();
        anim = GetComponent<Animator>();
    }

    public void die()
    {
        anim.SetBool("isHit", true);
        Destroy(gameObject, 1);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        //Play death animation, then terminate if touched by a bullet
        if (collision.gameObject.tag == "Bullet")
        {
            anim.SetBool("isHit", true);
            Destroy(gameObject, 0.3f);
        }
    }

    // Update is called once per frame
    void Update()
    {
        countDown -= Time.deltaTime;

        if (countDown <= 0)
        {
            //create a bullet
            GameObject sword = Instantiate(Resources.Load("sword"), transform.position, transform.rotation) as GameObject;
            countDown = (20 * Random.value) + 12;
            //and play the sound
            shoot.Play();
        }
    }
}